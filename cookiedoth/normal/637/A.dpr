program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type TType=record ind:Integer; li:Integer; end;
var
  i,j,n,indt,k,max,b,maxind:integer;
m:array[1..1000] of TType;
begin
 {   assign(Input,'input.txt');
    Reset(Input);
    Assign(Output,'output.txt');
    Rewrite(Output);     }
    Readln(n);
    k:=0;
    max:=0;
    for i:=1 to n do
    begin
      read(indt);
      b:=0;
      for j:=1 to k do
      begin
        if indt=m[j].ind then
        begin
          Inc(m[j].li);
          b:=1;
        end;
      end;
      if b=0 then
      begin
        Inc(k);
        m[k].ind:=indt;
        m[k].li:=1;
      end;
      for j:=1 to k do
      begin
        if m[j].li>max then
        begin
          max:=m[j].li;
          maxind:=m[j].ind;
        end;
      end;
    end;
    Writeln(maxind);
  //  Close(Input);
  //  Close(Output);
end.