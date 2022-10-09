uses math;

var 
    ntest: longint;
    l, r: longint;
    
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(l, r);
        writeln(min(r - l, (r - 1) div 2));
    end;
end.