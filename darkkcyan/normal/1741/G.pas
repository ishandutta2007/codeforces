uses math;

const maxn = 10101;
const maxk = 6;

var
    n, m, fc, k: longint;
    h: array[0..maxn] of longint;
    node: array[0..maxn * 2] of longint;
    next: array[0..maxn * 2] of longint;
    head: array[0..maxn] of longint;
    cur_edge: longint;
    p: array[0..maxk] of longint;
    no_car: array[0..maxn] of boolean;
    
procedure init_graph;
var i: longint;
begin
    for i := 0 to n do head[i] := -1;
    cur_edge := 0;
end;

procedure add_edge(u, v: longint);
begin
    next[cur_edge] := head[u];
    node[cur_edge] := v;
    head[u] := cur_Edge;
    inc(cur_edge);
end;

const checktest = -1;
procedure enter(testcase: longint);
var i: longint;
var u, v: longint;
begin
    read(n, m);
    init_graph;
    if testcase = checktest then writeln(n, ' ', m);
    for i := 1 to m do begin
        read(u, v);
        add_edge(u, v);
        add_edge(v, u);
        if testcase = checktest then writeln(u, ' ', v);
    end;
    read(fc);
    if testcase = checktest then writeln(fc);
    for i := 1 to fc do begin
        read(h[i]);
        if testcase = checktest then write(h[i], ' ');
    end;
    if testcase = checktest then writeln;
    for i := 1 to fc do no_car[i] := false;
    read(k);
    if testcase = checktest then writeln(k);
    for i := 1 to k do begin
        read(p[i]);
        no_car[p[i]] := true;
        if testcase = checktest then writeln(p[i], ' ');
    end;
    if testcase = checktest then writeln;
end;

var qu: array[0..2 * maxn] of longint;
var qu_head, qu_tail: ^longint;
procedure bfs(src: longint; var dist: array of longint);
var i: longint;
var u, v: longint;
begin
    for i := 0 to n do dist[i] := -1;
    dist[src] := 0;
    qu_head := @qu[0];
    qu_tail := @qu[0];
    
    qu_tail^ := src;
    inc(qu_tail);
    while qu_head <> qu_tail do begin
        u := qu_head^;
        inc(qu_head);
        i := head[u];
        while i <> -1 do begin
            v := node[i];
            i := next[i];
            if dist[v] <> -1 then continue;
            dist[v] := dist[u] + 1;
            qu_tail^ := v;
            inc(qu_tail);
        end;
    end;
end;

var
    dist1: array[0..maxn] of longint;
    dist_p: array[0..maxk, 0..maxn] of longint;
    dp: array[0..(1 shl maxk), 0..maxn] of boolean;
    
var
    ntest: longint;
    i, f, t: longint;
    route: array[0..maxk + 2] of longint;
    rc: longint;
    first_bit : longint;
    mask, submask: longint;
    dp2: array[0..(1 shl maxk), 0..maxn] of boolean;
    ans : longint;
    
function popcount(x: longint): longint;
begin
    if x = 0 then exit(0);
    exit(popcount(x shr 1) + (x and 1));
end;

var testcase: longint;

begin
    read(ntest);
    for testcase := 1 to ntest do begin
        dec(ntest);
        enter(testcase);
        bfs(1, dist1);
        for i := 1 to k do begin
            for f := i + 1 to k do begin
                if dist1[h[p[i]]] > dist1[h[p[f]]] then begin
                    t := p[i];
                    p[i] := p[f];
                    p[f] := t;
                end;
            end;
        end;
        
        for i := 1 to k do bfs(h[p[i]], dist_p[i]);
        
        for i := 1 to fc do dp[0][i] := true;
        
        writeln(stderr, '===');
        
        for mask := 1 to (1 shl k) - 1 do begin
            rc := 1;
            route[0] := 1;
            first_bit := -1;
            for i := 1 to k do begin
                if ((mask shr (i -1)) and 1) = 1 then begin
                    if first_bit = -1 then first_bit := i - 1;
                    route[rc] := h[p[i]];
                    inc(rc);
                end;
            end;
            for i := 1 to fc do begin
                dp[mask][i] := false;
                if no_car[i] then continue;
                if not dp[mask xor (1 shl first_bit)][i] then continue;
                route[rc] := h[i];
                if dist1[route[1]] + dist_p[first_bit + 1][route[2]] = dist1[route[2]] then begin
                    dp[mask][i] := true;
                    // writeln(stderr, mask, ' ', i, ' ', h[i]);
                end;
            end;
        end;
        
        for mask := 1 to (1 shl k) - 1 do 
            for i := 0 to fc do dp2[mask][i] := false;
        dp2[0][0] := true;
        
        for i := 1 to fc do begin
            for mask := 0 to (1 shl k) - 1 do begin
                dp2[mask][i] := dp2[mask][i - 1];
                for submask := 0 to (1 shl k) - 1 do begin
                    if (mask and submask) <> submask then continue;
                    if dp2[mask xor submask][i - 1] and dp[submask][i] then begin
                        dp2[mask][i] := true;
                        break;
                    end;
                end;
            end;
        end;
        ans := 0;
        for mask := 0 to (1 shl k) - 1 do begin
            writeln(stderr, mask, ' ', fc, ' ', dp2[mask][fc]);
            if dp2[mask][fc] then ans := max(ans, popcount(mask));
        end;
        writeln(k - ans);
    end;
end.