type
ukazat=^spis;
spis=record
  b,f: longint;
  zapr: integer;
  next: ukazat;
  end;
var
u,x,y: ukazat;
l: longint;
b,f: integer;
n,i: integer;
key,a: integer;
z: longint;

begin
readln(l,b,f);
readln(n);
new(u);
u^.b:=-b;
u^.f:=-b;
u^.zapr:=0;
new(u^.next);
u^.next^.b:=l+f;
u^.next^.f:=l+f;
u^.next^.zapr:=101;
u^.next^.next:=nil;

for i:=1 to n do begin
    readln(key,a);
    if key=1 then begin
        y:=u;
        x:=u^.next;
        z:=-1;
        while true do begin
            if y^.f+b+a+f<=x^.b then begin
                new(y^.next);
                y^.next^.b:=y^.f+b;
                y^.next^.f:=y^.f+b+a;
                y^.next^.next:=x;
                y^.next^.zapr:=i;
                z:=y^.f+b;
                end;
            if z<>-1 then break;
            if x^.b<>l+f then begin y:=x; x:=x^.next; end
                         else break;
            end;
        writeln(z);
        end;
    if key=2 then begin
        y:=u;
        x:=u^.next;
        while x^.zapr<>a do begin
            y:=x;
            x:=x^.next;
            end;
        y^.next:=x^.next;
        dispose(x);
        end;
    end;
end.