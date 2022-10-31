var
   a,b,c,a1,b1,c1,kol : longint;
begin
    read(a,b,c);
    read(a1,b1,c1);
    kol :=  0;
    if (a = a1) then inc(kol);
    if (b = b1) then inc(kol);
    if (c = c1) then inc(kol);
    if kol >= 1 then write('YES') else write('NO');
end.