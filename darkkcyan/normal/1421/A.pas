var
    n, a, b: longint;
    
begin
    read(n);
    while n > 0 do begin
        dec(n);
        read(a, b);
        writeln(a xor b);
    end;
end.