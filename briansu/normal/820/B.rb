n,k=gets.split(" ").map(&:to_i)
ans=0
mn=180.1
(3..n).each{|i|
	tmp=(180.0/n*(i-2)-k).abs
	if tmp<mn
		mn=tmp
		ans=i
	end
}
puts "2 1 #{ans}"