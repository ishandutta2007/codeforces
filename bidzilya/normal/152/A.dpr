program task_1;

{$APPTYPE CONSOLE}
uses
  Math,
  SysUtils;

var n,m,i,ans,j: integer;
    a: array[1..100]of char;
    s: array[1..100]of string;
begin
  readln(n,m);
  for i:=1 to m do a[i]:='0';
  for i:=1 to n do begin
    readln(s[i]);
    for j:=1 to m do
      if (s[i][j]>a[j])then
        a[j]:=s[i][j];
  end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (s[i][j]=a[j])then begin
        inc(ans);
        break;
      end;
  write(ans);
end.