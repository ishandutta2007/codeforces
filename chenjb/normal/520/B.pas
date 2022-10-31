type
  node=record
    x,w,next:longint;
  end;
var
  n,m,tot:longint;
  data:array[1..200000]of node;
  g:Array[1..50000]of longint;
  q:array[1..100001]of longint;
  d:array[1..50000]of longint;
  v:array[1..50000]of boolean;
procedure spfa;
var
  head,tail,p,x:longint;
begin
  head:=0;
  tail:=1;
  q[1]:=n;
  fillchar(v,sizeof(v),false);
  fillchar(d,sizeof(d),10);
  d[n]:=0;
  v[n]:=true;
  while head<>tail do
  begin
    head:=(head mod 100000)+1;
    x:=q[head];
    v[x]:=false;
    p:=g[x];
    while p<>-1 do
    begin
      if d[x]+data[p].w<d[data[p].x]then
      begin
        d[data[p].x]:=d[x]+data[p].w;
        if not v[data[p].x]then
        begin
          v[data[p].x]:=true;
          tail:=(tail mod 100000)+1;
          q[tail]:=data[p].x;
        end;
      end;
      p:=data[p].next;
    end;
  end;
  writeln(d[m]);
end;
procedure addedge(x,y,w:longint);
begin
  inc(tot);
  data[tot].x:=y;
  data[tot].w:=w;
  data[tot].next:=g[x];
  g[x]:=tot;
end;
var
  i:longint;
begin

  readln(n,m);
  fillchar(g,sizeof(g),255);
  tot:=0;
  for i:=1 to 10000 do
  begin
    if i<>1 then addedge(i,i-1,1);
    if i*2<=10000 then addedge(i,2*i,1);
  end;
  spfa;

end.