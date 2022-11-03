var
  a1,b1,c:array[0..5] of integer;
  a,b,mx,tmp,i,j:integer;

begin
  read(a,b);
  mx:=0;
  for i:=1 to 5 do begin
    a1[i]:=0;
    b1[i]:=0;
  end;
  i:=0;
  while a>0 do begin
    inc(i);
    a1[i]:=a mod 10;
    a:= a div 10;
    if a1[i]>mx then mx:=a1[i];
  end;
  a1[0]:=i;
  i:=0;
  while b>0 do begin
    inc(i);
    b1[i]:=b mod 10;
    b:= b div 10;
    if b1[i]>mx then mx:=b1[i];
  end;
  b1[0]:=i;
  if b1[0]>a1[0] then i:=b1[0] else i:=a1[0];
  inc(mx);
  tmp:=0;
  for j:=1 to i do begin
    c[j]:=a1[j]+b1[j]+tmp;
    tmp:=c[j] div mx;
    c[j]:=c[j] mod mx;
  end;
  if tmp>0 then inc(i);
  write(i);
end.