uses math;

var
    ntest: longint;
    n, a, b: int64;
    ans, ans2: int64;
    n_period: int64;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n, a, b);
        ans := n;
        n := (n + 1) div 2;
        n_period := n div a;
        ans2 := n_period * (a + b) + n mod a;
        if (n mod a) = 0 then dec(ans2, b);
        ans := max(ans, ans2);
        writeln(ans);
    end;
end.