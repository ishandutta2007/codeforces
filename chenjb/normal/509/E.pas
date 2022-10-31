var
  sum:Array[0..600001]of longint;
  now,ans:extended;
  s:ansistring;
  i:longint;
  len:longint;
begin

  fillchar(sum,sizeof(sum),0);
  readln(s);
  sum[0]:=0;
  len:=length(s);
  for i:=1 to len do
  begin
    if s[i] in ['I','E','A','O','U','Y']then inc(sum[i]);
    sum[i]:=sum[i]+sum[i-1];
  end;
  now:=0;
  ans:=0;
  for i:=1 to len do
  begin
    now:=now+(sum[len-i+1]-sum[i-1]);
    ans:=ans+now/i;
  end;
  writeln(ans:0:8);

end.