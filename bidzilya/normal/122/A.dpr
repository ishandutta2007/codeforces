program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var t: integer;

begin
  read(t);
  if (t mod 4=0)or
     (t mod 7=0)or
     (t mod 44=0)or
     (t mod 47=0)or
     (t mod 74=0)or
     (t mod 77=0)or
     (t mod 444=0)or
     (t mod 447=0)or
     (t mod 474=0)or
     (t mod 477=0)or
     (t mod 744=0)or
     (t mod 747=0)or
     (t mod 774=0)or
     (t mod 777=0)then
      write('YES')
  else
      write('NO');
end.