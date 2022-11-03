var
  n,i,k,j,pe,mn,n1,n2:integer;
  
begin
  read(n);
  read(pe);
  k:=pe;
  mn:=maxint;
  for i:=2 to n do begin
    read(j);
    if abs(j-k)<mn then begin mn:=abs(j-k); n1:=i-1; n2:=i; end;
    k:=j;
  end;
  if abs(j-pe)<mn then begin mn:=abs(j-pe); n1:=n; n2:=1; end;
  write(n1,' ',n2);
end.