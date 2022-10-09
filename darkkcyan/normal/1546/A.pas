const maxn = 1100;
var ntest, n: longint;
var a, b: array[0..maxn] of integer;
var ans: integer;
var u, v: array[0..maxn] of integer;
var i, f: integer;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do read(a[i]);
        for i := 1 to n do read(b[i]);
        
        ans := 0;
        f := 1;
        for i := 1 to n do begin
            while a[i] > b[i] do begin
                while (f <= n) and (a[f] >= b[f]) do inc(f);
                if f > n then break;
                inc(ans);
                dec(a[i]);
                inc(a[f]);
                u[ans] := i;
                v[ans] := f;
            end;
        end;
        for i := 1 to n do begin
            if a[i] <> b[i] then begin
                ans := -1;
                break;
            end;
        end;
        writeln(ans);
        if ans = -1 then continue;
        for i := 1 to ans do begin
            writeln(u[i], ' ', v[i]);
        end;
    end;
end.