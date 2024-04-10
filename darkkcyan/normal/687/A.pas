{$mode objfpc}
uses math;
const maxn = 101010;
type llnode = record
    next: ^llnode;
    val: longint;
end;
type pllnode = ^llnode;

function push(a: pllnode; val: longint): pllnode;
begin
    new(result);
    result^.next := a;
    result^.val := val;
end;

var n, m: longint;
var gr: array[0..maxn] of ^llnode;

var
    qu: array[0..maxn * 2] of longint;
    qul, qur: longint;
    color: array[0..maxn] of integer;
    cnt: array[0..1] of longint;

procedure bfs(u: longint);
var
    it: pllnode;
    v: longint;
begin
    qul := 0; qur := 1;
    qu[0] := u;
    color[u] := 0;
    while qul < qur do begin
        u := qu[qul]; inc(qul);
        inc(cnt[color[u]]);
        it := gr[u];
        while it <> nil do begin
            v := it^.val; it := it^.next;
            if (color[v] <> -1) then begin
                if (color[v] = color[u]) then begin
                    // writeln(u, ' ', color[u], ' ', v, ' ', color[v]);
                    writeln(-1);
                    halt;
                end;
                continue;
            end;
            color[v] := 1 - color[u];
            qu[qur] := v;
            inc(qur);
        end;
    end;
end;

var i, u, v: longint;
begin
    fillchar(gr, sizeof(gr), 0);
    read(n, m);
    for i := 1 to m do begin
        read(u); read(v);
        gr[u] := push(gr[u], v);
        gr[v] := push(gr[v], u);
    end;
    
    fillchar(color, sizeof(color), -1);
    cnt[0] := 0; cnt[1] := 0;
    for i := 1 to n do begin
        if color[i] <> -1 then continue;
        bfs(i);
    end;
    for i := 0 to 1 do begin
        writeln(cnt[i]);
        for u := 1 to n do
            if color[u] = i then write(u, ' ');
        writeln;
    end;
end.