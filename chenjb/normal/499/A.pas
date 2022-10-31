var
  l,r:Array[1..100]of longint;
  i,t,now,n,x:longint;
begin

  readln(n,x);
  for i:=1 to n do readln(l[i],r[i]);
  t:=0;
  now:=1;
  for i:=1 to n do
  begin
    while now+x<=l[i] do now:=now+x;
    if now<=r[i] then
    begin
      t:=t+r[i]-now+1;
      now:=r[i]+1;
    end;
  end;
  writeln(t);

end.