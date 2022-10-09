uses math;

var 
    n: longint;
    a, b, c: int64;
    ma, sum_res: int64;

begin
    read(n);
    while (n > 0) do begin
        dec(n);
        read(a, b, c);
        ma := max(a, max(b, c));
        sum_res := a + b + c - ma;
        if sum_res + 1 < ma then writeln('No')
        else writeln('Yes');
    end;
end.