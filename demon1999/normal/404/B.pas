{$N+}
var d,a,x,y:extended;
    n,i,p:longint;
begin
readln(a,d);
readln(n);
while d>4*a do d:=d-4*a;
x:=0;y:=0;
i:=0;p:=1;
while i<n do begin
      inc(i);
      if p=1 then x:=x+d;
      if p=2 then y:=y+d;
      if p=3 then x:=x-d;
      if p=4 then y:=y-d;
      while (x<0)or(x>a)or(y<0)OR(Y>A)do begin
            if x<0 then begin p:=4; y:=a+x;x:=0;end;
            if y<0 then begin p:=1; x:=-y; y:=0;end;
            if x>a then begin p:=2; y:=x-a; x:=a; end;
            if y>a then begin p:=3; x:=2*a-y; y:=a;end;
            end;
      writeln(x:0:5,' ',y:0:5);
      end;
end.