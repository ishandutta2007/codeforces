program project1;

{$apptype console}

uses Math, SysUtils;
var s,buf: string;
    stack: array[1..1000]of char;
    i,j,n: integer;
    del: boolean;
    c: char;

begin
  n:=0;
  readln(s);
  while (length(s)>0)do begin
    j:=pos('>',s);
    buf:=copy(s,2,j-2);
    delete(s,1,j);
    if (buf[1]='/')then begin
      del:=true;
      c:=buf[2];
    end else begin
      del:=false;
      c:=buf[1];
    end;
    if (not del)then begin
      inc(n);
      stack[n]:=c;
      for i:=1 to 2*n-2 do
        write(' ');
      writeln('<',c,'>');
    end else begin
      for i:=1 to 2*n-2 do
        write(' ');
      writeln('</',c,'>');
      dec(n);
    end;
  end;
end.