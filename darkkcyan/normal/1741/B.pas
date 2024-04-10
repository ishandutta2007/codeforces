var 
    ntest: longint;
    n: longint;
    i: longint;
    
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        if n = 3 then writeln(-1)
        else begin
            write(n, ' ', n - 1);
            for i := 1 to n - 2 do write(' ', i);
            writeln;
        end;
    end;
end.