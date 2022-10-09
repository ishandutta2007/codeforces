uses math;

const maxn = 555;

var
    n, m: longint;
    adj: array[0..maxn, 0..maxn] of boolean;
    
    qu: array[0..maxn * maxn] of longint;
    qb, qe: longint;
    
    col: array[0..maxn] of longint;
    
function bfs(start: longint): boolean;
var
    u, v: longint;
begin
    qb := 0;
    qe := 1;
    qu[0] := start;
    col[start] := 0;
    while qb < qe do begin
        u := qu[qb];
        inc(qb);
        for v := 1 to n do begin
            if u = v then continue;
            if adj[u][v] then continue;
            if col[v] <> -1 then begin
                if col[v] = col[u] then exit(false);
                continue;
            end;
            col[v] := 2 - col[u];
            qu[qe] := v;
            inc(qe);
        end;
    end;
    exit(true);
end;


var
    i: longint;
    u, v: longint;
    
function is_adj(x, y: longint): boolean;
begin
    if abs(x - y) <= 1 then exit(true);
    exit(false);
end;
begin
    read(n, m);
    fillchar(adj,sizeof(adj), 0);
    for i := 1 to m do begin
        read(u, v);
        adj[u][v] := true;
        adj[v][u] := true;
    end;
    
    fillchar(col, sizeof(col), 255);
    for i := 1 to n do begin
        u := 0;
        for v := 1 to n do begin
            if v <> i then inc(u, byte(adj[i][v]));
        end;
        if u = n - 1 then col[i] := 1;
    end;
    for i := 1 to n do begin
        if col[i] <> -1 then continue;
        if not bfs(i) then begin
            writeln('No');
            halt;
        end;
    end;
    
    for u := 1 to n do begin
        for v := 1 to n do begin
            if u = v then continue;
            if adj[u][v] <> is_adj(col[u], col[v]) then begin
                writeln('No');
                halt;
            end;
        end;
    end;
    
    writeln('Yes');
    for i := 1 to n do begin
        if col[i] = 0 then write('a')
        else if col[i] = 2 then write('c')
        else write('b');
    end;
end.