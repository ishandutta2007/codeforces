uses math;

procedure swap(var u: int64; var v: int64);
var t: int64;
begin t := u; u := v; v := t end;

procedure sort(var a: array of int64);
var i, f, g: longint;
var pivot: int64;
begin
    if length(a) <= 1 then exit();
    
    pivot := a[random(length(a))];
    f := high(a);
    i := low(a);
    g := low(a);
    while i <= f do begin
        if a[i] < pivot then begin
            swap(a[i], a[f]);
            dec(f);
        end else if a[i] > pivot then begin
            swap(a[i], a[g]);
            inc(g);
            inc(i);
        end else inc(i);
    end;
    
    sort(a[low(a)..g - 1]);
    sort(a[f..high(a)]);
end;

const maxn = 101010;
const maxnlogval = maxn * 20;

var n: longint;
var s: int64;
var eu, ev: array[0..maxn] of longint;
var typ: array[0..maxn] of byte;
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
        read(eu[i], ev[i], cost[i], typ[i]);
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
var root_typ: array[0..maxn] of byte;
procedure dfs(u, p: longint);
var i, v: longint;
begin
    factor[u] := 0;
    if (bound[u + 1] - bound[u] = 1) then begin
        factor[u] := 1;
    end;
    for i := bound[u] + 1 to bound[u + 1] do begin
        v := eu[gr[i]] + ev[gr[i]] - u;
        if v = p then continue;
        root_cost[v] := cost[gr[i]];
        root_typ[v] := typ[gr[i]];
        dfs(v, u);
        inc(factor[u], factor[v]);
    end;
end;

var ntest: longint;
var i, f: longint;
var sum: int64;
var ans: int64;
var arr: array[1..2, 0..maxnlogval] of int64;
var sz: array[1..2] of longint;

begin
    randomize;
    read(ntest);
    for ntest := 1 to ntest do begin
        read_input();
        dfs(1, 1);
        
        sum := 0;
        sz[2] := 0; sz[1] := 0;
        arr[1][0] := 0;
        arr[2][0] := 0;
        for i := 2 to n do begin
            inc(sum, root_cost[i] * factor[i]);
            while root_cost[i] > 0 do begin
                inc(sz[root_typ[i]]);
                arr[root_typ[i]][sz[root_typ[i]]] := ((root_cost[i] + 1) div 2) * factor[i];
                root_cost[i] := root_cost[i] div 2;
            end;
        end;
        if sum <= s then begin
            writeln(0);
            continue;
        end;
        
        sort(arr[1][1..sz[1]]);
        sort(arr[2][1..sz[2]]);
        
        if sz[1] = 0 then i := 0 else for i := 1 to sz[1] do begin 
            dec(sum, arr[1][i]);
            if sum <= s then break;
        end;
        
        ans := 1000 * 1000 * 1000;
        if sum <= s then ans := i;
        
        for f := 1 to sz[2] do begin
            dec(sum, arr[2][f]);
            while (i > 0) and (sum + arr[1][i] <= s) do begin
                inc(sum, arr[1][i]);
                dec(i);
            end;
            if sum <= s then ans := min(ans, i + f * 2);
        end;
        
        writeln(ans);
    end;
end.