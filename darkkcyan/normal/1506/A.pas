var
    ntest: longint;
    n, m: int64;
    x: int64;
    r, c: int64;
    
begin
    read(ntest);
    while (ntest > 0) do begin
        dec(ntest);
        read(n, m, x);
        dec(x);
        c := x div n;
        r := x mod n;
        x := r * m + c + 1;
        writeln(x);
    end;
end.