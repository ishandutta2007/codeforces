uses math;

const maxn = 201010;

var
    n, k: longint;
    c, ans: ansistring;
    l, r: array[0..maxn] of longint;
    
var
    in_order: array[0..maxn] of longint;
    timer: longint;
    
procedure build_in_order(u: longint);
begin
    if u = 0 then exit;
    build_in_order(l[u]);
    in_order[timer] := u;
    inc(timer);
    build_in_order(r[u]);
end;

var good, duplicated: array[0..maxn] of boolean;

procedure dfs(u, cost: longint);
begin
    duplicated[u] := false;
    if u = 0 then exit;
    if cost > k then exit;
    dfs(l[u], cost + 1);
    if duplicated[l[u]] then 
        duplicated[u] := true
    else if good[u] then begin
        duplicated[u] := true;
        dec(k, cost);
    end;
    if duplicated[u] then dfs(r[u], 1);
end;
    
var i, nxt: longint;
begin
    readln(n, k);
    readln(c);
    for i := 1 to n do begin
        read(l[i], r[i]);
    end;
    timer := 1;
    build_in_order(1);
    good[in_order[n]] := false;
    nxt := in_order[n];
    for i := n - 1 downto 1 do begin
        if c[in_order[i]] <> c[in_order[i + 1]] then nxt := in_order[i + 1];
        good[in_order[i]] := c[in_order[i]] < c[nxt];
    end;
    dfs(1, 1);
    ans := '';
    for i := 1 to n do begin
        ans := ans + c[in_order[i]];
        if duplicated[in_order[i]] then ans := ans + c[in_order[i]];
    end;
    writeln(ans);
end.