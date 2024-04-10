var
  i,n,ans:longint;
  t1,t2:extended;
  x1,y1,x2,y2,a,b,c:int64;
begin

  read(x1,y1,x2,y2);
  ans:=0;
  read(n);
  for i:=1 to n do
  begin
    read(a,b,c);
    t1:=a*x1+b*y1+c;
    t2:=a*x2+b*y2+c;
    if extended(t1)*extended(t2)<0 then inc(ans);
  end;
  writeln(ans);

end.