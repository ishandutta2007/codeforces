program project1;

{$apptype console}

uses Math, SysUtils;
type block = array[1..4]of integer;
var
  i,j,k,n,g,m,d: integer;
  t: array[1..1000]of block;
  c: char;

procedure povorot(i: integer);
var buf: integer;
begin
    buf:=t[i][1];
    t[i][1]:=t[i][3];
    t[i][3]:=t[i][4];
    t[i][4]:=t[i][2];
    t[i][2]:=buf;
end;

function ravno(i1,i2: integer): boolean;
var ok: boolean;
    i: integer;
begin
  for i:=1 to 4 do 
    if (t[i1][i]<>t[i2][i])then begin
      ravno:=false;
      exit;
    end;
  ravno:=true;
end;

begin
  readln(n);
  m:=0;
  for i:=1 to n do begin
    read(c);
    t[i][1]:=ord(c)-ord('0');
    readln(c);
    t[i][2]:=ord(c)-ord('0');
    read(c);
    t[i][3]:=ord(c)-ord('0');
    readln(c);
    t[i][4]:=ord(c)-ord('0');
    readln;

    k:=-1;
    for j:=1 to m do
      for g:=1 to 4 do begin
        povorot(i);
        if (ravno(i,j))then
          k:=j;
      end;

    if (k=-1)then begin
      inc(m);
      for j:=1 to 4 do
        t[m][j]:=t[i][j];
    end;

  end;
  writeln(m);

end.