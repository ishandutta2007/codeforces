var
        a,b,c,t:longint;
begin
        readln(a,b,c);
        if a>b then begin t:=a;a:=b;b:=t; end;
        if a+c<=b then writeln(2*(a+c)) else
                writeln(2*(b+(c-(b-a)) div 2));
end.