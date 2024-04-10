a,b=0,gets.split.map(&:to_i)
gets.chomp.split.map(&:to_i).sort.reverse.each_with_index{|x,i| a+=(x-1)*2 if i%b[1]==0}
puts a