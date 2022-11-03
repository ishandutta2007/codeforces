program task_4;

{$APPTYPE CONSOLE}
uses windows;
const nmax = 700;
      md = round(1e9)+7;
var dp: array[1..nmax,1..nmax,0..7,0..7]of int64;
    n: integer;
    s: string;

function getbit(cl,x :integer): boolean;
var c: integer;
begin
  c:=(cl shr x)and 1;
  if (c = 1)then getbit:=true
            else getbit:=false;
end;

function rec(l,r, lc,rc: integer): int64;
var i,sum: integer;
    c: array[1..2,0..2]of boolean;
    t: int64;
begin
  if (dp[l,r,lc,rc]<>-1)then begin
    rec:=dp[l,r,lc,rc];
    exit;
  end;
  if (l>=r)then begin
    dp[l,r,lc,rc]:=1;
    rec:=1;
    exit;
  end;
  sum:=0;
  i:=l;
  while (i<=r)do begin
    if (s[i]=')')then dec(sum);
    if (s[i]='(')then inc(sum);
    if (sum=0)then break;
    inc(i);
  end;
  c[1,0]:=getbit(lc,0);c[1,1]:=getbit(lc,1);c[1,2]:=getbit(lc,2);
  c[2,0]:=getbit(rc,0);c[2,1]:=getbit(rc,1);c[2,2]:=getbit(rc,2);
  t:=0;
  if (i<r)then begin
    if (c[1,0])then t:=(t + (rec(l+1,i-1,6,7)*rec(i+1,r,7,rc))mod md)mod md;
    if (c[1,1])then t:=(t + (rec(l+1,i-1,5,7)*rec(i+1,r,7,rc))mod md)mod md;
    if (c[1,2])then begin
      t:=(t + (rec(l+1,i-1,7,6)*rec(i+1,r,6,rc))mod md)mod md;
      t:=(t + (rec(l+1,i-1,7,5)*rec(i+1,r,5,rc))mod md)mod md;
    end;
    dp[l,r,lc,rc]:=t;
    rec:=t;
    exit;
  end;
  if (c[2,2])then begin
    if (c[1,0])then t:=(t + rec(l+1,r-1,6,7))mod md;
    if (c[1,1])then t:=(t + rec(l+1,r-1,5,7))mod md;
  end;
  if (c[1,2])then begin
    if (c[2,0])then t:=(t + rec(l+1,r-1,7,6))mod md;
    if (c[2,1])then t:=(t + rec(l+1,r-1,7,5))mod md;
  end;
  dp[l,r,lc,rc]:=t;
  rec:=t;
end;
{ o = red 1 = green 2 = black }

begin
  readln(s);
  n:=length(s);
  fillchar(dp,sizeof(dp),-1);
  write(rec(1,n,7,7));
end.