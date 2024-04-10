var
  q,n,l,r,i,t1,t2,t3:longint;
  s:ansistring;
  x,y,z:array[0..100001]of longint;
begin
 
  x[0]:=0;
  y[0]:=0;
  z[0]:=0;
  readln(s);
  n:=length(s);
  for i:=1 to n do
  begin
    x[i]:=x[i-1];
    y[i]:=y[i-1];
    z[i]:=z[i-1];
    if s[i]='x' then inc(x[i]);
    if s[i]='y' then inc(y[i]);
    if s[i]='z' then inc(z[i]);
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(l,r);
    if r-l+1<3 then writeln('YES')
    else
    begin
      t1:=x[r]-x[l-1];
      t2:=y[r]-y[l-1];
      t3:=z[r]-z[l-1];
      if (abs(t1-t2)<=1)and(abs(t1-t3)<=1)and(abs(t2-t3)<=1)then writeln('YES')
      else writeln('NO');
    end;
  end;
  
end.