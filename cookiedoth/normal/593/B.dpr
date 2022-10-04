program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type TLine=record
  k,b:Int64;
end;
type TInters=record
  y1,y2:Int64;
end;
type TMinMax=record
  min,max:Int64;
end;
const max=100000; {    }
type
  list = array[1..max] of TInters;
var
  m:array[1..100000] of TLine;
  minmax:array[1..100000] of TMinMax;
  my:list;
  x1,x2,kminmax:Integer;
  n,i:Integer;
  lasty1:Int64;
procedure quicksort(var a: list; Lo,Hi: integer);
var
  num:array[1..100000] of Integer;
  procedure sort(l,r: integer);
  var
    i,j: integer;
    x,y,z,xval,xvaln:Int64;
  begin
    i:=l; j:=r; x :=(r+l) div 2; xval:=a[x].y1; xvaln:=num[x];{ x :=(r+l) div 2; -     }
    repeat
      while (a[i].y1<xval)or((a[i].y1=xval)and(num[i]<xvaln)) do i:=i+1; {> -   }
      while (xval<a[j].y1)or((a[j].y1=xval)and(xvaln<num[j])) do j:=j-1; {> -   }
      if i<=j then
      begin
        y:=a[i].y1; z:=a[i].y2; a[i]:=a[j]; a[j].y1:=y; a[j].y2:=z;
        y:=num[i]; num[i]:=num[j]; num[j]:=y;
        i:=i+1; j:=j-1
      end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r)
  end; {sort}
begin {quicksort}
  for i:=1 to n do
    num[i]:=i;
  sort(Lo,Hi)
end;
begin
{  Assign(Input,'input.txt');
  Reset(Input);
  Assign(Output,'output.txt');
  Rewrite(Output);   }
  Readln(n);
  Readln(x1,x2);
  for i:=1 to n do
  begin
    Readln(m[i].k,m[i].b);
  end;
  for i:=1 to n do
  begin
    my[i].y1:=x1*m[i].k+m[i].b;
    my[i].y2:=x2*m[i].k+m[i].b;
  end;
  quicksort(my,1,n);
  lasty1:=-999999999999999999;
  kminmax:=0;
  for i:=1 to n do
  begin
    if my[i].y1>lasty1 then
    begin
      Inc(kminmax);
      minmax[kminmax].min:=my[i].y2;
      minmax[kminmax].max:=my[i].y2;
      lasty1:=my[i].y1;
    end;
    if my[i].y1=lasty1 then
    begin
      if my[i].y2>minmax[kminmax].max then minmax[kminmax].max:=my[i].y2;
      if my[i].y2<minmax[kminmax].min then minmax[kminmax].min:=my[i].y2;
    end;
  end;
  for i:=2 to kminmax do
  begin
    if minmax[i].min<minmax[i-1].max then
    begin
      Writeln('yes');
      Halt(0);
    end;
  end;
  Writeln('no');
 { Readln(n);
  Close(input);
  Close(Output); }
end.