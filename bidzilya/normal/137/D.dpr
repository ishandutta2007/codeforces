{$APPTYPE CONSOLE}
var
  s:string;
  w:array[1..500]of integer;
  p,ans,minp:array[0..500,0..500]of integer;
  i,j,t,k,n:integer;

procedure palindrome(l,r:integer);
var
  i,j:integer;
begin
  i:=l;
  j:=r;
  while i<j do
  begin
    if s[i]<>s[j]then
      s[j]:=s[i];
    inc(i);
    dec(j);
  end;
end;

begin
  {assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  }
  readln(s);
  read(n);
  for i:=length(s) downto 1 do
    for j:=i+1 to length(s) do
      minp[i,j]:=minp[i+1,j-1]+ord(s[i]<>s[j]);

  
  for i:=0 to length(s)do
    for j:=0 to length(s)do
      ans[i,j]:=10000;
  ans[0,0]:=0;
  for i:=1 to length(s)do
    for j:=0 to i-1 do
      for t:=0 to length(s)do
        if ans[j,t]+minp[j+1,i]<ans[i,t+1]then
        begin
          ans[i,t+1]:=ans[j,t]+minp[j+1,i];
          p[i,t+1]:=j;
        end;

  t:=n;
  for i:=1 to n-1 do
    if ans[length(s),i]<ans[length(s),t]then
      t:=i;
  writeln(ans[length(s),t]);
  k:=0;
  n:=length(s);
  for i:=t downto 1 do
  begin
    inc(k);
    w[k]:=n;
    n:=p[n,i];
  end;
  t:=1;
  for k:=k downto 1 do
  begin
    palindrome(t,w[k]);
    for i:=t to w[k] do
      write(s[i]);
    t:=w[k]+1;
    if k>1 then
      write('+');
  end;
end.