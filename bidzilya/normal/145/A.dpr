program project1;

{$apptype console}

uses Math, SysUtils;
var s1,s2: string;
    c4,c7,i: integer;

begin
  readln(s1);
  readln(s2);
  c4:=0;c7:=0;
  for i:=1 to length(s1)do
    if (s1[i]<>s2[i])then begin
      if (s1[i]='4')then inc(c4);
      if (s1[i]='7')then inc(c7);
    end;
  i:=min(c4,c7);dec(c4,i);dec(c7,i);
  writeln(i+c4+c7);
end.