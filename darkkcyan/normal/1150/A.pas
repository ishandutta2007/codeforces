uses math;

var
    n, m, r: longint;
    min_share, max_buy: longint;
    x: longint;
    
begin
    read(n, m, r);
    read(min_share);
    while n > 1 do begin
        dec(n);
        read(x);
        min_share := min(min_share, x);
    end;
    read(max_buy);
    while m > 1 do begin
        dec(m);
        read(x);
        max_buy := max(max_buy, x);
    end;
    
    if max_buy > min_share then begin
        r := r mod min_share + r div min_share * max_buy;
    end;
    writeln(r);
        
end.