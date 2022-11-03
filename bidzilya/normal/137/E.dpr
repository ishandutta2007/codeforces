program task_E;

{$apptype console r+ q+}
uses Math;
const nmax = 200000;
      alp:set of char = ['a','e','i','o','u','A','E','I','O','U'];
var p,s: array[0..nmax]of integer;
    i,j,n,len,ta: integer;
    t: string;

function Binary(z,l,r: integer): integer;
var ans,m: integer;
begin
  ans:=0;
  while (l<=r)do begin
    m:=(l+r)shr 1;
    if (s[m]>=z)then begin
      ans:=max(ans,m);
      l:=m+1;
    end
    else r:=m-1;
  end;
  Binary:=ans;
end;

begin
  readln(t);
  p[0]:=0;
  n:=length(t);
  for i:=1 to n do begin
    p[i]:=p[i-1];
    if (t[i] in alp)then
      dec(p[i])
    else
      inc(p[i],2);
  end;
  s[n]:=p[n];
  for i:=n-1 downto 1 do
    s[i]:=max(s[i+1],p[i]);
  ta:=0;
  for i:=0 to n do begin
    j:=Binary(p[i],i,n);
    ta:=max(ta,j-i);
  end;
  if (ta = 0)then begin
    write('No solution');
    halt;
  end;
  j:=0;
  for i:=ta to n do
    if (p[i] - p[i-ta]>=0)then inc(j);
  write(ta,' ',j);
end.