x = 0
(eval(gets) & 255).to_s.split('').map(&:ord).each{|c|
	if x < c
		print "+" * (c - x)
	end
	if x > c
		print "-" * (x - c)
	end
	print "."
	x = c
}
puts