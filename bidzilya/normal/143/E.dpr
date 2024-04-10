{$APPTYPE CONSOLE}
const x:array[1..4,1..5]of integer =
        ((0,1,2,1,1),
         (0,0,1,2,0),
         (2,0,1,2,2),
         (1,1,0,1,2));
      y:array[1..4,1..5]of integer =
        ((0,0,0,1,2),
         (0,1,1,1,2),
         (0,1,1,1,2),
         (0,1,2,2,2));
var buf,n,m,i,j,ans:integer;
    t,p:array[1..10,1..10]of byte;

procedure rec(xx,yy,tans:integer);
var i,j,mans:integer;
    ok:boolean;

function can(v:integer):boolean;
var i,tx,ty:integer;
    ok:boolean;
begin
  ok:=true;
  for i:=1 to 5 do begin
    tx:=xx+x[v,i];
    ty:=yy+y[v,i];
    if (p[ty,tx]<>0)then begin
              ok:=false;
              break;
    end;
  end;
  can:=ok;
end;

procedure put(v:integer);
var i,tx,ty:integer;
begin
  for i:=1 to 5 do begin
    tx:=xx+x[v,i];
    ty:=yy+y[v,i];
    p[ty,tx]:=tans+1;
  end;
end;

procedure deput(v:integer);
var i,tx,ty:integer;
begin
  for i:=1 to 5 do begin
    tx:=xx+x[v,i];
    ty:=yy+y[v,i];
    p[ty,tx]:=0;
  end;
end;

begin
  if (xx>m-2)then begin
    xx:=1;
    inc(yy);
  end;
  if (yy>n-2)then begin
    if (tans>ans)then begin
      ans:=tans;
      for i:=1 to n do
        for j:=1 to m do
          t[i,j]:=p[i,j];
    end;
    exit;
  end;
  mans:=(m-xx+(n-yy)*m)div 5+tans;
  if (mans<=ans)then exit;
  ok:=true;
  if (can(1))then begin
    put(1);
    ok:=false;
    rec(xx+2,yy,tans+1);
    deput(1);
  end;
  if (can(2))then begin
    put(2);
    ok:=false;
    rec(xx+2,yy,tans+1);
    deput(2);
  end;
  if (can(3))then begin
    put(3);
    ok:=false;
    rec(xx+3,yy,tans+1);
    deput(3);
  end;
  if (can(4))then begin
    put(4);
    ok:=false;
    rec(xx+2,yy,tans+1);
    deput(4);
  end;
  if (n<=8)or(m<=8)then ok:=true;
  if (ok)then rec(xx+1,yy,tans);
end;

begin
  read(n,m);
  ans:=0;
  fillchar(t,sizeof(t),0);
  fillchar(p,sizeof(p),0);
  if (m>2)and(n>2)then
    rec(1,1,0);
  writeln(ans);
  for i:=1 to n do begin
    for j:=1 to m do
      if (t[i,j]=0)then write('.')else
        write(chr(t[i,j]+64));
    writeln;
  end;
end.