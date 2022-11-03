program D;

{$APPTYPE CONSOLE}
uses Math, SysUtils;
var s,s1,s2: string;
    a,b,cnt: array[0..9]of integer;
    i,j,n,ta: integer;

procedure check(x,y: integer);
var tt,i,j: integer;
    aa,bb: array[0..9]of integer;
begin
  if (a[x]<1)or(b[y]<1)then exit;
  for i:=0 to 9 do begin
    aa[i]:=a[i];
    bb[i]:=b[i];
  end;
  tt:=1;
  dec(aa[x]);dec(bb[y]);
  for i:=0 to 9 do begin
    j:=min(aa[i],bb[9-i]);
    inc(tt,j);
    dec(aa[i],j);dec(bb[9-i],j);
  end;
  j:=min(aa[0],bb[0]);
  inc(tt,j);
  if (tt>ta)then begin
    s1:=inttostr(x);
    s2:=inttostr(y);
    ta:=tt;
  end;
end;
begin
  s1:='';s2:='';
  readln(s);
  n:=length(s);
  for i:=0 to 9 do begin
    a[i]:=0;
    b[i]:=0;
  end;
  for i:=1 to n do begin
    inc(a[ord(s[i])-ord('0')]);
    inc(b[ord(s[i])-ord('0')]);
  end;
  ta:=0;
  check(2,8);
  check(3,7);
  check(4,6);
  check(5,5);
  check(9,1);
  if (s1<>'')then begin
    dec(a[ord(s1[1])-ord('0')]);
    dec(b[ord(s2[1])-ord('0')]);
  end;
  for i:=0 to 9 do begin
    cnt[i]:=min(a[i],b[9-i]);
    a[i]:=a[i]-cnt[i];
    b[9-i]:=b[9-i]-cnt[i];
  end;
  ta:=min(a[0],b[0]);
  a[0]:=a[0]-ta;b[0]:=b[0]-ta;
  for i:=0 to 9 do
    for j:=1 to a[i]do
      write(i);
  for i:=0 to 9 do
    for j:=1 to cnt[i]do
      write(i);
  write(s1);
  for i:=1 to ta do write(0);
  writeln;
  for i:=0 to 9 do
    for j:=1 to b[i]do
      write(i);
  for i:=9 downto 0 do
    for j:=1 to cnt[9-i]do
      write(i);
  write(s2);
  for i:=1 to ta do write(0);
end.