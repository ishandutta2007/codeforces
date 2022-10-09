uses math;

const maxn = 101010;
var
    ntest: longint;
    n, m: longint;
    pos: array[0..maxn] of longint;
    i, u, cur: longint;
    ans: int64;

begin
    read(ntest);
    while (ntest > 0) do begin
        dec(ntest);
        read(n, m);
        for i := 1 to n do begin
            read(u);
            pos[u] := i;
        end;
        ans := 0;
        cur := 0;
        for i := 1 to m do begin
            read(u);
            u := pos[u];
            if u < cur then inc(ans)
            else begin
                inc(ans, 2 * (u - i) + 1);
                cur := u;
            end;
            
        end;

        writeln(ans);
    end;
end.