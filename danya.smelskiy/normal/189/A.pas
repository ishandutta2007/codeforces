var n,a,b,k,i,j,c,ans: longint;
   Begin
    Read(n);
    Read(a,b,c);
    For i:=0 to (n div a) do
      begin
       if i*a>n then break;
       For j:=0 to (n div b) do
          begin
           if (i*a)+(j*b)>n then break;
           if (n-(i*a)-(j*b)) mod c=0 then
              begin
                if i+j+((n-(i*a)-(j*b)) div c)>ans then ans:=i+j+((n-(i*a)-(j*b)) div c);
              end;
          end;
      end;
      Write(ans);
   End.