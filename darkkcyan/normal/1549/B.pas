uses math;

const maxn = 201010;

var
    ntest: longint;
    n: longint;
    u, v: ansistring;
    i: longint;
    ans: longint;
    mark: array [0..maxn] of boolean;

begin
    readln(ntest);
    while ntest > 0 do begin
        dec(ntest);
        readln(n);
        readln(u);
        readln(v);
        for i := 1 to n do mark[i] := false;
        ans := 0;
        for i := 1 to n do begin
            if v[i] = '0' then continue;
            if u[i] = '0' then begin
                inc(ans);
                continue;
            end;
            if (i > 1) and (u[i - 1] = '1') and not mark[i - 1] then begin
                mark[i - 1] := true;
                inc(ans);
            end else if (i < n) and (u[i + 1] = '1') then begin
                mark[i + 1] := true;
                inc(ans);
            end;
        end;
        writeln(ans);
    end;
end.