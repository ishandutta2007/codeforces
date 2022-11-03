program task_44;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var a,b,c,d,i:integer;
    s:string;
begin
  read(a,b,c,d);
  if (c=d)then begin
    if (a-c>=1)and(b-c>=0)then begin
      for i:=1 to a-c-1 do write(4);
      for i:=1 to c do write(47);
      for i:=1 to b-c do write(7);
      write(4);
      halt;
    end else
    if (b-c>=1)and(a-c>=0)then begin
      write(7);
      for i:=1 to a-c do write(4);
      for i:=1 to c do write(47);
      for i:=1 to b-c-1 do write(7);
      halt;
    end else begin
      write(-1);
      halt;
    end;
  end else
  if (c=d+1)then begin
    if (a>=c)and(b>=c)then begin
      for i:=1 to a-c do write(4);
      for i:=1 to c do write(47);
      for i:=1 to b-c do write(7);
      halt;
    end else begin
      write(-1);
      halt;
    end;
  end else
  if (d=c+1)then begin
    if (a>=d)and(b>=d)then begin
      write(7);
      for i:=1 to a-d do write(4);
      for i:=1 to c do write(47);
      for i:=1 to b-d do write(7);
      write(4);
      halt;
    end else begin
      write(-1);
      halt;
    end;
  end;
  write(-1);
  halt;
end.