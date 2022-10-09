var
    ntest, n, x, y: int64;
    
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n, x);
        inc(n);
        while n > 0 do begin
            dec(n);
            read(y);
            x := x xor y;
        end;
        if x mod 2 = 0 then writeln('Alice')
        else writeln('Bob');
    end;
end.