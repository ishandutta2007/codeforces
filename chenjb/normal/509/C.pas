var
  a:array[0..600]of longint;
  len,t,b1,b2,last,temp,n:longint;
procedure print;
var
  i:longint;
begin
  for i:=len downto 1 do write(a[i]);
  writeln;
end;
procedure main1(x:longint);
var
  i,j:longint;
begin
  i:=1;
  while x>0 do
  begin
    if a[i]=9 then inc(i)
    else
    begin
      inc(a[i]);
      dec(x);
    end;
  end;
  if len<i then len:=i;
end;
procedure main2(x:longint);
var
  i,j:longint;
begin
  i:=1;
  while x<=0 do
  begin
    x:=x+a[i];
    a[i]:=0;
    inc(i);
  end;
  while a[i]=9 do
  begin
    x:=x+a[i];
    a[i]:=0;
    inc(i);
  end;
  inc(a[i]);
  dec(x);
  if len<i then len:=i;
  main1(x);
end;
var
  i:longint;
begin

  fillchar(a,sizeof(a),0);
  len:=1;
  read(n);
  read(b1);
  main1(b1);
  print;
  for i:=2 to n do
  begin
    read(b2);
    t:=b2-b1;
    b1:=b2;
    if t>0 then main1(t)
    else main2(t);
    print;
  end;

end.