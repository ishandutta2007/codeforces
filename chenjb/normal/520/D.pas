type
  node1=record
    max,min:longint;
  end;
  node2=record
    x,y:longint;
  end;
  node3=record
    p,x,y,next:longint;
  end;
const
  inf=10000007;
  MD=1000000009;
var
  st:Array[1..600000]of node1;
  v:array[-1..100100]of boolean;
  m,tot,i,j,k,t,p:longint;
  hash:array[0..inf-1]of longint;
  data:Array[1..200000]of node3;
  a:array[1..200000]of node2;
  lift,ans:array[1..100100]of longint;
  sum,power:int64;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
procedure insert(t,l,r,k,p:longint);
var
  mid:longint;
begin
  if l=r then
  begin
    if p>0 then
    begin
      st[t].max:=p;
      st[t].min:=p;
    end
    else
    begin
      st[t].max:=0;
      st[t].min:=2147483647;
    end;
    exit;
  end;
  mid:=(l+r)div 2;
  if k<=mid then insert(2*t,l,mid,k,p)
  else insert(2*t+1,mid+1,r,k,p);
  st[t].max:=max(st[2*t].max,st[2*t+1].max);
  st[t].min:=min(st[2*t].min,st[2*t+1].min);
end;
procedure hashinsert(p,x,y:longint);
var
  t:int64;
begin
  t:=abs(int64(x))*129+abs(int64(y))*131;
  t:=t mod inf;
  inc(tot);
  data[tot].p:=p;
  data[tot].x:=x;
  data[tot].y:=y;
  data[tot].next:=hash[t];
  hash[t]:=tot;
end;
function exist(x,y:longint):longint;
var
  t:int64;
  p:longint;
begin
  t:=abs(int64(x))*129+abs(int64(y))*131;
  t:=t mod inf;
  p:=hash[t];
  while p<>-1 do
  begin
    if (data[p].x=x)and(data[p].y=y)then exit(data[p].p);
    p:=data[p].next;
  end;
  exit(-1);
end;
function legal(x,y:longint):boolean;
var
  t:longint;
begin
  t:=exist(x+1,y);
  if t<>-1 then if v[t] then if lift[t]<=1 then exit(false);
  t:=exist(x+1,y-1);
  if t<>-1 then if v[t] then if lift[t]<=1 then exit(false);
  t:=exist(x+1,y+1);
  if t<>-1 then if v[t] then if lift[t]<=1 then exit(false);
  exit(true);
end;
begin

  readln(m);
  fillchar(v,sizeof(v),true);
  v[-1]:=false;
  fillchar(hash,sizeof(hash),255);
  tot:=0;
  for i:=1 to m do
  begin
    readln(a[i].y,a[i].x);
    hashinsert(i,a[i].x,a[i].y);
  end;
  fillchar(lift,sizeof(lift),0);
  for i:=1 to 600000 do begin st[i].max:=0; st[i].min:=2147483647; end;

  for i:=1 to m do
  begin
    p:=exist(a[i].x+1,a[i].y);
    if p<>-1 then inc(lift[p]);
    p:=exist(a[i].x+1,a[i].y-1);
    if p<>-1 then inc(lift[p]);
    p:=exist(a[i].x+1,a[i].y+1);
    if p<>-1 then inc(lift[p]);
  end;
  for i:=1 to m do
    if legal(a[i].x,a[i].y) then
       insert(1,1,m,i,i);

  t:=0;
  for i:=m downto 1 do
  begin
    if t=0 then k:=st[1].max
    else k:=st[1].min;
    ans[i]:=k;
    insert(1,1,m,k,-k);
    v[k]:=false;

    p:=exist(a[k].x+1,a[k].y);
    if p<>-1 then if v[p] then dec(lift[p]);
    p:=exist(a[k].x+1,a[k].y-1);
    if p<>-1 then if v[p] then dec(lift[p]);
    p:=exist(a[k].x+1,a[k].y+1);
    if p<>-1 then if v[p] then dec(lift[p]);

    p:=exist(a[k].x,a[k].y-2);
    if p<>-1 then if v[p] then if not legal(a[p].x,a[p].y) then insert(1,1,m,p,-p);
    p:=exist(a[k].x,a[k].y-1);
    if p<>-1 then if v[p] then if not legal(a[p].x,a[p].y) then insert(1,1,m,p,-p);
    p:=exist(a[k].x,a[k].y+1);
    if p<>-1 then if v[p] then if not legal(a[p].x,a[p].y) then insert(1,1,m,p,-p);
    p:=exist(a[k].x,a[k].y+2);
    if p<>-1 then if v[p] then if not legal(a[p].x,a[p].y) then insert(1,1,m,p,-p);


    p:=exist(a[k].x-1,a[k].y);
    if (p<>-1)and(legal(a[p].x,a[p].y))and(v[p])then insert(1,1,m,p,p);
    p:=exist(a[k].x-1,a[k].y-1);
    if (p<>-1)and(legal(a[p].x,a[p].y))and(v[p])then insert(1,1,m,p,p);
    p:=exist(a[k].x-1,a[k].y+1);
    if (p<>-1)and(legal(a[p].x,a[p].y))and(v[p])then insert(1,1,m,p,p);

    t:=t xor 1;
  end;
  power:=1;
  sum:=0;
  for i:=1 to m do
  begin
    sum:=(sum+power*int64(ans[i]-1)mod MD)mod MD;
    power:=power*m mod MD;
  end;
  writeln(sum mod MD);

end.