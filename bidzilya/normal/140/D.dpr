{$APPTYPE CONSOLE}

var
  a:array[1..100]of integer;
  tt,ta,ka,n,i,j,tmp:integer;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[j]<a[i] then begin tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp; end;
  ta:=0;
  ka:=0;
  tt:=10;
  for i:=1 to n do
    if (tt+a[i]<=360)then begin tt:=tt+a[i]; inc(ka); end
    else if (tt+a[i]>720)then break
    else begin tt:=tt+a[i]; ta:=ta+tt-360; inc(ka); end;
  write(ka,' ',ta);
end.