program task_1;

{$APPTYPE CONSOLE}

var a: array[1..12]of integer;
    buf,k,ans,i,j: integer;

begin
  read(k);
  for i:=1 to 12 do read(a[i]);
  for i:=1 to 11 do
    for j:=i+1 to 12 do
      if (a[j]>a[i])then begin
        buf:=a[i];a[i]:=a[j];a[j]:=buf;
      end;
  ans:=0;
  i:=1;
  buf:=0;
  while (i<=12)do begin
    if (buf>=k)then break;
    inc(ans);
    buf:=buf+a[i];
    inc(i);
  end;
  if (buf>=k)then write(ans)
             else write(-1);
end.