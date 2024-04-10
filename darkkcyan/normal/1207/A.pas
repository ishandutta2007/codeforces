uses math;

var 
    t, b, p, f, h, c: longint;    
    i: longint;
    ans: longint;
begin
    readln(t);
    while t > 0 do begin
        dec(t);
        read(b, p, f);
        read(h, c);
        ans := 0;
        b := b div 2;
        for i := 0 to p do begin
            if b < i then break;
            ans := max(ans, i * h + min(b - i, f) * c);
        end;
        writeln(ans);
    end;
end.