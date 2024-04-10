uses math;

const maxn = 101010;
var lchild, rchild: array[0..maxn] of longint;
var val: array[0..maxn] of int64;

procedure swap(var u: longint; var v: longint);
var temp: longint;
begin temp := u; u := v; v := temp; end;

function merge(u, v: longint): longint;
begin
    if u = -1 then exit(v);
    if v = -1 then exit(u);
    if val[u] < val[v] then swap(u, v);
    if random(2) = 0 then swap(lchild[u], rchild[u]);
    rchild[u] := merge(rchild[u], v);
    exit(u);
end;

procedure make_node(id: longint; v: int64);
begin
    val[id] := v; lchild[id] := -1; rchild[id] := -1;
end;

var n: longint;
var s: int64;
var eu, ev: array[0..maxn] of longint;
var cost: array[0..maxn] of int64;
var bound: array[0..maxn] of longint;
var gr: array[0..2 * maxn] of longint;

procedure read_input;
var i: longint;
begin
    read(n);
    read(s);
    for i := 1 to n do bound[i] := 0;
    for i := 2 to n do begin
        read(eu[i], ev[i], cost[i]);
        inc(bound[eu[i]]);
        inc(bound[ev[i]]);
    end;
    for i := 2 to n do inc(bound[i], bound[i - 1]);
    bound[n + 1] := bound[n];
    
    for i := 2 to n do begin
        gr[bound[eu[i]]] := i;
        gr[bound[ev[i]]] := i;
        dec(bound[eu[i]]);
        dec(bound[ev[i]]);
    end;
end;

var factor: array [0..maxn] of longint;
var root_cost: array[0..maxn] of int64;
procedure dfs(u, p: longint);
var i, v: longint;
begin
    factor[u] := 0;
    if (bound[u + 1] - bound[u] = 1) then begin
        factor[u] := 1;
    end;
    // writeln(stderr, u, ' ', bound[u], ' ', bound[u + 1]); 
    for i := bound[u] + 1 to bound[u + 1] do begin
        // writeln(stderr, i); 
        v := eu[gr[i]] + ev[gr[i]] - u;
        // writeln(stderr, v); 
        if v = p then continue;
        root_cost[v] := cost[gr[i]];
        dfs(v, u);
        inc(factor[u], factor[v]);
    end;
end;

var ntest: longint;
var i, root: longint;
var sum: int64;
var ans: int64;

begin
    randomize;
    read(ntest);
    for ntest := 1 to ntest do begin
        // writeln(stderr); 
        read_input();
        dfs(1, 1);
        
        root := -1;
        sum := 0;
        for i := 2 to n do begin
            make_node(i, ((root_cost[i] + 1) div 2) * factor[i]);
            root := merge(root, i);
            inc(sum, root_cost[i] * factor[i]);
        end;
        
        ans := 0;
        while sum > s do begin
            i := root;
            root := merge(lchild[root], rchild[root]);
            inc(ans);
            dec(sum, root_cost[i] * factor[i]);
            root_cost[i] := root_cost[i] div 2;
            if root_cost[i] > 0 then begin
                make_node(i, ((root_cost[i] + 1) div 2) * factor[i]);
                inc(sum, root_cost[i] * factor[i]);
                root := merge(root, i);
            end;
        end;
        writeln(ans);
    end;
end.