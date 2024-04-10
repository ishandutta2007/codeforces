const nnn = 60;
var
    p: array[1..nnn] of int64;
    a, ans: array[1..5] of int64;
    left: int64;
    i, f, n: int32;

begin
    readln(n);
    for i := 1 to n do read(p[i]);
    for i := 1 to 5 do begin
        read(a[i]);
        ans[i] := 0;
        //writeln(stderr, a[i], ' ');
    end;
    left := 0;
    for i := 1 to n do begin
        inc(left, p[i]);
        for f := 5 downto 1 do begin
            inc(ans[f], left div a[f]);
            left := left mod a[f];
        end;
    end;
    for i := 1 to 5 do write(ans[i], ' ');
    writeln; writeln(left);
end.