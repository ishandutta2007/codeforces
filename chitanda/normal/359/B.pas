var
  i,n,k,p,t,j:longint;
  a:Array[0..101000]of longint;
begin
  readln(n,k);
  if k=0 then
  begin
    for i:=1 to n do
      a[i*2-1]:=n+i;
    for i:=1 to n do
      a[i*2]:=i;
  end else
  begin
    a[1]:=1; a[2]:=1+k;
    i:=n+2; j:=2; p:=3;
    repeat
      if j=1+k then inc(j);
      a[p]:=i; a[p+1]:=j;
      inc(i); inc(j);
      inc(p,2);
    until p>2*n;
  end;
  for i:=1 to 2*n do write(a[i],' ');
end.