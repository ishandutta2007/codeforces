gets
s=0
a=0
for x in gets.chomp.split.map(&:to_i)
	s += x;
	a += -s if s < 0
	s -= s if s < 0
end

puts a