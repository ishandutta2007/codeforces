value = gets.to_i
funkcja = ""
STDIN.each_line {|l| funkcja += l}
funkcja.sub!(/int/, "def")
funkcja.sub!(/int/, "")
funkcja.sub!(/\{/, "\nBAZINGA")
funkcja.sub!(/\}/, "\nend")

# zamieniamy if (n) return x; na if (n) then return x
#loop do
#  funkcja =~ /if/
#  if (funkcja.nil?) then break end
#end
funkcja.gsub!(/if(.*?)return(.*?);/m, 'if \1 then return \2 end'+"\n")
funkcja.gsub!(/;/,"\n")
funkcja.gsub!(/(\d+)/, 'Syfownik.new(\1)')
funkcja.gsub!(/BAZINGA/,'if ($mem[n.p] != -1) then return Syfownik.new($mem[n.p]) end'+"\n")

$mem = Array.new
(0..32767).each do |i| $mem[i] = -1 end

class Syfownik
   def initialize(x)
      @p = x
   end
   
   def p
     @p
   end
   
   def + (a)
     Syfownik.new((@p + a.p)%32768)
   end
   def - (a)
     Syfownik.new((@p - a.p)%32768)
   end
   def * (a)
     Syfownik.new((@p * a.p) % 32768)
   end
   def / (a)
     Syfownik.new(@p / a.p)
   end
   def < (a)
     @p < a.p
   end
   def > (a)
     @p > a.p
   end
   def == (a)
     @p == a.p
   end
   
   def to_s
     "Syfownik nr " + @p.to_s
   end
end

#puts funkcja
eval funkcja

maks = -1
(0..32767).each do |i| 
   ourval = f(Syfownik.new(i)).p
   $mem[i] = ourval
   if (ourval==value) then maks = i end
end
puts maks