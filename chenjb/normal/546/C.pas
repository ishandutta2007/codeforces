type
  node=record
    x,y,next:int64;
  end;
const
  inf=10000007;
var
  g:array[0..inf-1]of longint;
  data:Array[1..1000000]of node;
  power:Array[0..12]of int64;
  n:longint;
  a,b:int64;
  tt,x,y:int64;
  time,tot,tot1,tot2,i:longint;
function hash(a,b:int64):boolean;
var
  p:longint;
  t:int64;
begin
  t:=a*129+b;
  t:=t mod inf;
  p:=g[t];
  while p<>-1 do
  begin
    if (data[p].x=a)and(data[p].y=b)then exit(true);
    p:=data[p].next;
  end;
  inc(tot);
  data[tot].x:=a;
  data[tot].y:=b;
  data[tot].next:=g[t];
  g[t]:=tot;
  exit(false);
end;
begin
  read(n);
  read(tot1);
  a:=0;
  tt:=1;
  for i:=1 to tot1 do
  begin
    read(x);
    dec(x);
    a:=a+int64(x)*tt;
    tt:=tt*10;
  end;
  read(tot2);
  b:=0;
  tt:=1;
  for i:=1 to tot2 do
  begin
    read(x);
    dec(x);
    b:=b+int64(x)*tt;
    tt:=tt*10;
  end;
  power[0]:=1;
  for i:=1 to 12 do power[i]:=power[i-1]*10;
  tot:=0;
  for i:=0 to inf-1 do g[i]:=-1;
  hash(a,b);
  time:=0;
  while true do
  begin
    x:=a mod 10;
    a:=a div 10;
    dec(tot1);
    y:=b mod 10;
    b:=b div 10;
    dec(tot2);
    if x>y then
    begin
      a:=a+power[tot1]*y;
      inc(tot1);
      a:=a+power[tot1]*x;
      inc(tot1);
      inc(time);
      if tot2=0 then
      begin
        writeln(time,' ',1);
        halt;
      end;
    end
    else
    begin
      b:=b+power[tot2]*x;
      inc(tot2);
      b:=b+power[tot2]*y;
      inc(tot2);
      inc(time);
      if tot1=0 then
      begin
        writeln(time,' ',2);
        halt;
      end;
    end;
    if hash(a,b) then
    begin
      writeln(-1);
      halt;
    end;
  end;
  close(input);
  close(output);
end.