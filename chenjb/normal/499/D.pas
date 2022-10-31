var
  f:Array[0..5000,0..5000]of extended;
  t:array[1..5000]of longint;
  p:array[1..5000]of extended;
  i,j,n,m:longint;
  ans,tmp,pp:extended;
begin
  
  readln(n,m);
  for i:=1 to n do
  begin
    readln(p[i],t[i]);
    p[i]:=p[i]/100;
  end;
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  ans:=0;
  for i:=1 to n do
  begin
    tmp:=0;
    pp:=1;
    for j:=1 to t[i] do pp:=pp*(1-p[i]);
    for j:=0 to m do
    begin
      if j-1>=0 then tmp:=tmp+f[i-1,j-1];
      if j-t[i]-1>=0 then tmp:=tmp-f[i-1,j-t[i]-1]*pp;
      f[i,j]:=tmp*p[i];
      if j-t[i]>=0 then f[i,j]:=f[i,j]+f[i-1,j-t[i]]*pp;
      tmp:=tmp*(1-p[i]);
      ans:=ans+f[i,j];
    end;
  end;
  writeln(ans:0:10);

end.