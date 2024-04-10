var
  n,i,j,r2:integer;
  r,r1:real;
begin
  read(n);
  for i:=2 to n do begin
    r:=n/i;
    for j:=1 to i div 2 do begin
      r1:=r*j;
      if (round(r1)=r1)and((n-r1)=round(n-r1)) then begin
        r2:=round(r1);
        if (r2 mod 2=0)and((n-r2) mod 2=0)then begin write('YES'); halt; end;
      end;
    end;
  end;
  write('NO');
end.