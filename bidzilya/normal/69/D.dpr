program task_4;

{$APPTYPE CONSOLE}
const t = 222;
var x,y,i,n,d:integer;
    ax,ay:array[1..20]of integer;
    ans:array[-t..t,-t..t]of byte;

function rec(tx,ty: integer): boolean;
var i:integer;
begin
  if (ans[ty,tx]<>1)then begin
    if (ans[ty,tx]=2)then rec:=true else
      rec:=false;
    exit;
  end;
  if (tx<>x)and(ty<>y)and(sqr(ty)+sqr(tx)>d)then begin
    ans[ty,tx]:=2;
    rec:=true;
    exit;
  end;
  for i:=1 to n do
    if (ty+ay[i]<=t)and(ty+ay[i]>=-t)and
       (tx+ax[i]<=t)and(tx+ax[i]>=-t)and
       (not rec(tx+ax[i],ty+ay[i]))then begin
      ans[ty,tx]:=2;
      rec:=true;
      exit;
    end;
  ans[ty,tx]:=3;
  rec:=false;
end;

begin
  read(x,y,n,d);
  d:=d*d;
  for i:=1 to n do read(ax[i],ay[i]);
  fillchar(ans,sizeof(ans),1);
  if (rec(x,y))then write('Anton')
               else write('Dasha');
end.