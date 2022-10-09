uses math;
const inf: int64 = 1000 * 1000 * 1000 * 1000 * 1000;

var
    ntest: longint;
    sum: int64;
    c, i: longint;
    ans: int64;
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(c, sum);
        ans := inf;
        for i := 1 to c do begin
            ans := min(ans, sqr(sum div i) * (i - sum mod i) + sqr(sum div i + 1) * (sum mod i));
        end;
        writeln(ans);
    end;
end.