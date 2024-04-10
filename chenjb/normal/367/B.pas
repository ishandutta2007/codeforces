type
  link=^longint;
  node=record
    x:longint;
    p:link;
  end;
var
  data:array[1..600000]of node;
  a,b:array[1..210000]of longint;
  ans:array[1..210000]of longint;
  time,now,need:Array[1..600000]of longint;
  v:array[1..210000]of boolean;
  tot,n,m,p:longint;
procedure qsort(left,right:longint);
var
  i,j:longint;
  mid:longint;
  t:node;
begin
  if left>=right then exit;
  i:=left;
  j:=right;
  mid:=data[(i+j)div 2].x;
  repeat
    while data[i].x<mid do inc(i);
    while data[j].x>mid do dec(j);
    if i<=j then
    begin
      t:=data[i];
      data[i]:=data[j];
      data[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  qsort(left,j);
  qsort(i,right);
end;
procedure init;
var
  i,j,t:longint;
begin
  read(n,m,p);
  tot:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    inc(tot);
    data[tot].x:=a[i];
    data[tot].p:=@a[i];
  end;
  for i:=1 to m do
  begin
    read(b[i]);
    inc(tot);
    data[tot].x:=b[i];
    data[tot].p:=@b[i];
  end;
  qsort(1,tot);
  t:=1;
  data[1].p^:=t;
  for i:=2 to tot do
  begin
    if data[i].x<>data[i-1].x then inc(t);
    data[i].p^:=t;
  end;
  fillchar(need,sizeof(need),0);
  for i:=1 to m do inc(need[b[i]]);
end;
procedure update(i,t:longint);
begin
  if time[t]<>i then
  begin
    time[t]:=i;
    now[t]:=0;
  end;
  inc(now[t]);
end;
procedure main;
var
  i,start,ti,j,t,k:longint;
begin
  fillchar(v,sizeof(v),false);
  fillchar(time,sizeof(time),0);
  fillchar(now,sizeof(now),0);
  for i:=1 to p do
  begin
    start:=i;
    j:=i;
    t:=0;
    while j<=n do
    begin
      inc(t);
      update(i,a[j]);
      while now[a[j]]>need[a[j]] do
      begin
        dec(now[a[start]]);
        dec(t);
        start:=start+p;
      end;
      if t=m then v[start]:=true;
      j:=j+p;
    end;
  end;
  tot:=0;
  for i:=1 to n do if v[i] then
  begin
    inc(tot);
    ans[tot]:=i;
  end;
  writeln(tot);
  if tot=0 then exit;
  write(ans[1]);
  for i:=2 to tot do write(' ',ans[i]);
  writeln;
end;
begin

  init;
  main;
 
end.