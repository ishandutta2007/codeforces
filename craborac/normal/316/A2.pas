program ABBYY_3_A;
var a, n, i, j, b, col:integer;
    w:array[1..10] of char;
    f:array[1..100000] of integer;
    s:string;
    q:int64;
begin
  readln(s);
  n:=length(s);
  a:=0;
  q:=1;
  col:=0;
  for i:=1 to n do
  begin
    b:=0;
    if s[i]='?' then
    begin
      if i=1 then f[i]:=9
      else
      begin
        f[i]:=1;
        col:=col+1;
      end;
    end
    else if ((s[i]='0') or (s[i]='1') or (s[i]='2') or (s[i]='3') or (s[i]='4') or (s[i]='5') or (s[i]='6') or (s[i]='7') or (s[i]='8') or (s[i]='9')) then f[i]:=1
    else
    begin
      if i=1 then
      begin
        f[i]:=9;
        w[1]:=s[i];
        a:=1;
      end
      else
      begin
        for j:=1 to a do if s[i]=w[j] then b:=b+1;
        if b>0 then f[i]:=1
        else
        begin
          f[i]:=10-a;
          w[a+1]:=s[i];
          a:=a+1;
        end;
      end;
    end;
    q:=q*f[i];
  end;
  write(q);
  for i:=1 to col do write('0');
end.